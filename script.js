function fetchEmployeeList() {
    fetch('http://localhost:3000/employees')  
        .then(response => {
            if (!response.ok) {
                throw new Error('Network response was not ok');
            }
            return response.json();
        })
        .then(data => {
            renderEmployeeList(data);
        })
        .catch(error => {
            console.error('Error fetching employee list:', error);
        });
}

// Render list of employees
function renderEmployeeList(employees) {
    const employeeListContainer = document.getElementById("employeeList");
    const employeeList = document.createElement("ul");
    employeeListContainer.innerHTML = "";  // Clear previous list

    employees.forEach(employee => {
        const li = document.createElement("li");
        li.textContent = `${employee.Name} (ID: ${employee.ID})`;  
        employeeList.appendChild(li);
    });

    employeeListContainer.appendChild(employeeList);
    employeeListContainer.style.display = "block";
}

// Render training list with specific training items
function renderTrainingList() {
    const trainings = [
        'Closing Procedure',
        'Opening Procedure',
        'Biohazard Training',
        'Handling Tours Training',
        'Handling Emergency Procedures'
    ];

    const trainingListContainer = document.getElementById("trainingList");
    const trainingListItems = document.getElementById("trainingListItems");
    trainingListItems.innerHTML = "";  // Clear previous list

    trainings.forEach(training => {
        const li = document.createElement("li");
        li.textContent = training;
        trainingListItems.appendChild(li);
    });

    trainingListContainer.style.display = "block";
}

// // Randomize employee and display result
function randomizeEmployee() {
    fetch('http://localhost:3000/randomiseEmployee')  
        .then(response => {
            if (!response.ok) {
                throw new Error('Network response was not ok');
            }
            return response.json();
        })
        .then(data => {
            // Display the randomized employee on the screen
            alert(`Employee Randomized: ${data.Name} (ID: ${data.ID})`);
            const employeeDisplay = document.getElementById('randomEmployeeDisplay');
            employeeDisplay.textContent = `Employee: ${data.Name} (ID: ${data.ID})`;
            employeeDisplay.style.display = "block";

            // Send the randomized employee to the server to store in the database
            fetch('http://localhost:3000/storeRandomEmployee', {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json',
                },
                body: JSON.stringify({ Name: data.Name, ID: data.ID })  // Send employee data
            })
            .then(response => {
                if (!response.ok) {
                    throw new Error('Failed to store employee in the database');
                }
                return response.text();
            })
            .then(message => {
                console.log(message);
            })
            .catch(error => {
                console.error('Error storing randomized employee:', error);
            });
        })
        .catch(error => {
            console.error('Error randomizing employee:', error);
        });
}

// View completed stewards (randomized employees)
function viewCompletedStewards() {
    fetch('http://localhost:3000/completedStewards')
        .then(response => {
            if (!response.ok) {
                throw new Error('Network response was not ok');
            }
            return response.json();
        })
        .then(data => {
            // Display the list of completed stewards
            const completedStewardsContainer = document.getElementById('completedStewardsList');
            completedStewardsContainer.innerHTML = '';  // Clear previous list
            
            if (data.length === 0) {
                completedStewardsContainer.textContent = "No completed stewards found.";
            } else {
                const ul = document.createElement('ul');
                
                data.forEach(steward => {
                    const li = document.createElement('li');
                    li.textContent = `${steward.Name} (ID: ${steward.ID})`;  // Adjust to match DB columns
                    ul.appendChild(li);
                });
                
                completedStewardsContainer.appendChild(ul);
            }
            completedStewardsContainer.style.display = "block";
        })
        .catch(error => {
            console.error('Error viewing completed stewards:', error);
        });
}


// Remove employee
function removeEmployee() {
    const id = prompt("Enter ID of employee to remove:");
    if (id) {
        fetch('http://localhost:3000/removeEmployee', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json',
            },
            body: JSON.stringify({ ID: id }),  
        })
        .then(response => {
            if (!response.ok) {
                throw new Error('Network response was not ok');
            }
            return response.text();
        })
        .then(message => {
            alert(message);
            fetchEmployeeList();  // Refresh employee list
        })
        .catch(error => {
            console.error('Error removing employee:', error);
        });
    }
}

// Add a new employee
function addNewEmployee() {
    const name = prompt("Enter name of new employee:");
    const id = prompt("Enter ID of new employee:");
    if (name && id) {
        fetch('http://localhost:3000/addEmployee', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json',
            },
            body: JSON.stringify({ Name: name, ID: id }),  
        })
        .then(response => {
            if (!response.ok) {
                throw new Error('Network response was not ok');
            }
            return response.text();
        })
        .then(message => {
            alert(message);
            fetchEmployeeList();  // Refresh employee list
        })
        .catch(error => {
            console.error('Error adding employee:', error);
        });
    }
}

// Show employee list
function showEmployeeList() {
    fetchEmployeeList();
    document.getElementById("employeeList").style.display = "block";
    document.getElementById("trainingList").style.display = "none";
}

// Show training list
function showTrainingList() {
    renderTrainingList();
    document.getElementById("trainingList").style.display = "block";
    document.getElementById("employeeList").style.display = "none";
}

// Handle login
function login() {
    const username = document.getElementById("username").value;
    const password = document.getElementById("password").value;
    const loginMessage = document.getElementById("loginMessage");

    if (username === "admin" && password === "password") {
        loginMessage.textContent = "Login successful!";
        document.getElementById("loginContainer").style.display = "none";
        document.getElementById("appContainer").style.display = "block";
        document.getElementById("dashboard").style.display = "block";
        hideBearImage();
    } else {
        loginMessage.textContent = "Invalid username or password. Please try again.";
    }
}

// Hide bear image on login
function hideBearImage() {
    const bearImageContainer = document.getElementById("bearImageContainer");
    if (bearImageContainer) {
        bearImageContainer.style.display = "none";
    }
}

document.addEventListener("DOMContentLoaded", function() {
     
});
