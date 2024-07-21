const express = require('express');
const bodyParser = require('body-parser');
const sqlite3 = require('sqlite3').verbose();

const app = express();
const port = 3000;

const db = new sqlite3.Database("/Users/ellakerrigan/Downloads/SRC_DATABASE.db");

app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());

// Route to get employee list
app.get('/employees', function(req, res) {
    db.all('SELECT * FROM Employee', function(err, rows) {
        if (err) {
            console.error('Error fetching employees from database:', err.message);
            res.status(500).send('Error fetching employees from database');
        } else {
            res.json(rows);
        }
    });
});

// Route to add new employee
app.post('/addEmployee', function(req, res) {
    const { name } = req.body;
    db.run(`INSERT INTO employee (name) VALUES (?)`, [name], function(err) {
        if (err) {
            console.error('Error adding employee to database:', err.message);
            res.status(500).send('Error adding employee to database');
        } else {
            res.status(200).send('Employee added successfully');
        }
    });
});

// Route to remove employee
app.post('/removeSteward', function(req, res) {
    const { id } = req.body;
    db.run(`DELETE FROM employee WHERE id = ?`, [id], function(err) {
        if (err) {
            console.error('Error removing employee from database:', err.message);
            res.status(500).send('Error removing employee from database');
        } else {
            res.status(200).send('Employee removed successfully');
        }
    });
});

// Route to add a new steward
app.post('/addSteward', function(req, res) {
    const { name, id } = req.body;
    db.run(`INSERT INTO steward (name, id) VALUES (?, ?)`, [name, id], function(err) {
        if (err) {
            console.error('Error adding steward to database:', err.message);
            res.status(500).send('Error adding steward to database');
        } else {
            res.status(200).send('Steward added successfully');
        }
    });
});

// Serve static files from the "public" directory
app.use(express.static('public'));

// Start server
app.listen(port, function() {
    console.log(`Server is running on http://localhost:${port}`);
});
