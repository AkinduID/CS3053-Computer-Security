// A code segment in a web page that prevents an attacker to use SQL injection

const http = require('http');
const mysql = require('mysql');

// Set up the MySQL connection
const db = mysql.createConnection({
    host: 'localhost',
    user: 'root',
    password: 'password',
    database: 'test_db'
});

// Secure login function with parameterized queries
const secureLogin = (username, password, callback) => {
    const sql = `SELECT * FROM users WHERE username = ? AND password = ?`;
    db.query(sql, [username, password], (error, results) => {
        if (error) {
            callback(error, null);
            return;
        }
        callback(null, results);
    });
};

// HTTP server demonstrating secure login
http.createServer((req, res) => {
    if (req.method === 'POST') {
        let body = '';
        req.on('data', chunk => { body += chunk; });
        req.on('end', () => {
            const { username, password } = JSON.parse(body);
            secureLogin(username, password, (err, results) => {
                if (err) {
                    res.writeHead(500);
                    res.end('Database error');
                    return;
                }

                if (results.length > 0) {
                    res.writeHead(200);
                    res.end('Login successful');
                } else {
                    res.writeHead(401);
                    res.end('Login failed');
                }
            });
        });
    } else {
        res.writeHead(404);
        res.end('Not Found');
    }
}).listen(3000);

console.log('Server running on http://localhost:3000');
