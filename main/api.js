fetch('https://api.thingspeak.com/channels/1722122/feeds.json?api_key=3Q0RQ9U3MDSNZUEA&results=1')
  .then(response => response.json())
  .then(json =>{
    document.getElementById("Temperature").innerHTML = json["feeds"][0].field1;
    document.getElementById("Humidity").innerHTML = json["feeds"][0].field2;
    document.getElementById("Gaz").innerHTML = json["feeds"][0].field3;
    // document.getElementById("Fire").innerHTML = json["feeds"][0].field4;
    document.getElementById("smoke").innerHTML = json["feeds"][0].field5;
    
  })

// fetch('https://api.thingspeak.com/channels/1722122/feeds.json?api_key=3Q0RQ9U3MDSNZUEA&results=1')
//   .then(response => response.json())
//   .then(json => console.log(json))

// data = JSON.parse(console.log())
// document.getElementById("Temperature").innerHTML = data[1].field1
// document.getElementById("Humidity").innerHTML = data[1].field2
// document.getElementById("Gaz").innerHTML = data[1].field3
// document.getElementById("Fire").innerHTML = data[1].field
  


