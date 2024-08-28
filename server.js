//Front-End server
const express = require('express');  
const bodyParser = require('body-parser');
const sqlite3 = require('sqlite3').verbose();
const cors = require('cors');  

const app = express();  
const port = 3000;

const db = new sqlite3.Database("/Users/ellakerrigan/Downloads/SRC_DATABASE.db");

app.use(cors());  
app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());

// Route to get employee list
app.get('/employees', (req, res) => {
    db.all('SELECT * FROM employees', (err, rows) => {
        if (err) {
            console.error('Error fetching employees from database:', err.message);
            res.status(500).send('Error fetching employees from database');
        } else {
            res.json(rows); // This will return the employee data from the database
        }
    });
});

// Route to add new employee
app.post('/addEmployee', (req, res) => {
    const { Name, ID } = req.body;  
    db.run('INSERT INTO employees (Name, ID) VALUES (?, ?)', [Name, ID], function(err) {
        if (err) {
            console.error('Error adding employee to database:', err.message);
            res.status(500).json({ error: 'Error adding employee to database' });
        } else {
            res.status(200).json({ message: 'Employee added successfully' });
        }
    });
});

// Route to remove employee
app.post('/removeEmployee', (req, res) => {
    const { ID } = req.body;
    db.run('DELETE FROM employees WHERE ID = ?', [ID], function(err) {
        if (err) {
            console.error('Error removing employee from database:', err.message);
            res.status(500).json({ error: 'Error removing employee from database' });
        } else {
            res.status(200).json({ message: 'Employee removed successfully' });
        }
    });
});
// // Route to randomize employee
app.get('/randomiseEmployee', (req, res) => {
    db.get('SELECT * FROM employees ORDER BY RANDOM() LIMIT 1', [], (err, row) => {
        if (err) {
            console.error(err);
            res.status(500).send('Error fetching employee');
        } else {
            res.json(row);  // Send randomized employee data
        }
    });
});
// Route to store the randomized employee in the database
app.post('/storeRandomEmployee', (req, res) => {
    const { Name, ID } = req.body;

    db.run('INSERT INTO randomized_employees (Name, ID) VALUES (?, ?)', [Name, ID], function(err) {
        if (err) {
            console.error(err);
            res.status(500).send('Failed to store randomized employee');
        } else {
            res.send('Randomized employee stored successfully');
        }
    });
});

// Route to get all completed stewards (randomized employees)
app.get('/completedStewards', (req, res) => {
    db.all('SELECT * FROM randomized_employees', [], (err, rows) => {
        if (err) {
            console.error(err);
            res.status(500).send('Error retrieving completed stewards');
        } else {
            res.json(rows);  // Send back the list of completed stewards
        }
    });
});

app.use(express.static('public'));

// Start server
app.listen(port, () => {
    console.log(`Server is running on http://localhost:${port}`);
});
