// fetch list of employees from server
function fetchEmployeeList() {
    fetch('/employees')
    .then(response => response.json())
    .then(data => {
        renderEmployeeList(data);
    })
    .catch(error => {
        console.error('Error fetching employee list:', error);
    });
}

// render list of employees
function renderEmployeeList(employees) {
    const employeeListItems = document.getElementById("employeeList");
    const employeeListsItems = employee.querySelector("u1");
    employeeListItems.innerHTML = "";

    employees.forEach(employee => {
        const li = document.createElement("li");
        li.textContent = `${employee.name} (ID: ${employee.id})`;
        employeeListItems.appendChild(li);
    });

    employeeList.style.display = "block"; 
}

// render training list
function renderTrainingList() {
    const trainingListItems = document.getElementById("trainingListItems");
    trainingListItems.innerHTML = "<h2>Training List</h2><ul>";

    trainings.forEach(training => {
        trainingListItems.innerHTML += `<li>${training.name} (ID: ${training.id})</li>`;
    });

    trainingListItems.innerHTML += "</ul>";
}

// randomize employee
function randomizeEmployee() {
    fetch('/randomizeEmployee') // does route exist on the server
    .then(response => response.json())
    .then(data => {
        alert(`Employee Randomized: ${data.name}`);
    })
    .catch(error => {
        console.error('Error randomizing employee:', error);
    });
}

// view completed stewards
function viewCompletedStewards() {
    fetch('/completedStewards') // does route exist on the server
    .then(response => response.json())
    .then(data => {
        alert(`Completed Stewards: ${data.join(', ')}`);
    })
    .catch(error => {
        console.error('Error viewing completed stewards:', error);
    });
}

//  remove steward
function removeSteward() {
    const id = prompt("Enter ID of steward to remove:");
    fetch('/removeSteward', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json',
        },
        body: JSON.stringify({ id }),
    })
    .then(response => response.text())
    .then(message => {
        alert(message);
        fetchEmployeeList(); // Refresh the employee list?
    })
    .catch(error => {
        console.error('Error removing steward:', error);
    });
}

// add a new steward
function addNewSteward() {
    const name = prompt("Enter name of new steward:");
    const id = prompt("Enter ID of new steward:");
    fetch('/addSteward', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json',
        },
        body: JSON.stringify({ name, id }),
    })
    .then(response => response.text())
    .then(message => {
        alert(message);
        fetchEmployeeList(); // Refresh the employee list
    })
    .catch(error => {
        console.error('Error adding steward:', error);
    });
}

// show the employee list
function showEmployeeList() {
    fetchEmployeeList();
    
}

// show the training list
function showTrainingList() {
    renderTrainingList();
    document.getElementById("trainingList").style.display = "block";
    document.getElementById("employeeList").style.display = "none";
}

// Function to handle login
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

function hideBearImage() {
    var bearImageContainer = document.getElementById("bearImageContainer");
    if (bearImageContainer) {
        bearImageContainer.style.display = "none";
    }
}

// Ensure that the script is properly included
document.addEventListener("DOMContentLoaded", function() {
    fetchEmployeeList(); // Fetch employees when the page loads
});
