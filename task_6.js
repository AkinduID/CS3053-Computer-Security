// A code segment in a web page that allows an attacker to use SQL injection

const http = require('http');
const mysql = require('mysql');

// Set up the MySQL connection
const db = mysql.createConnection({
    host: 'localhost',
    user: 'root',
    password: 'password',
    database: 'test_db'
});

// Vulnerable login function
// In the vulnerableLogin function, 
// username and password are directly included in the SQL query 
// without parameterization or escaping
// SELECT * FROM users WHERE username = 'admin' OR '1'='1' AND password = 'any';

const vulnerableLogin = (username, password, callback) => {
    const sql = `SELECT * FROM users WHERE username = '${username}' AND password = '${password}'`;
    db.query(sql, (error, results) => {
        if (error) {
            callback(error, null);
            return;
        }
        callback(null, results);
    });
};

// Simple HTTP server to demonstrate login
http.createServer((req, res) => {
    if (req.method === 'POST') {
        let body = '';
        req.on('data', chunk => { body += chunk; });
        req.on('end', () => {
            const { username, password } = JSON.parse(body);
            vulnerableLogin(username, password, (err, results) => {
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
