var gateway = 'ws://localhost:9002';
const socket = new WebSocket(gateway); 

socket.onopen = () => {
    console.log("WebSocket connection opened");

    // Send data to the server
    const data = { 
        method: "GET" 
    };

    socket.send(JSON.stringify(data)); 
};

socket.onmessage = (event) => {
    let parsedData = JSON.parse(event.data);

    console.log("Data received from server:", parsedData);

    document.getElementById("temperature").innerHTML = parsedData["temperature"];
    document.getElementById("humidity").innerHTML = parsedData["humidity"];
    document.getElementById("pressure").innerHTML = parsedData["pressure"];
};

socket.onerror = (error) => {
    console.error("WebSocket error:", error);
};