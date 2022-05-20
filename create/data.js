// var details= [];
// var i=0
// function save(){
//     user = document.getElementById('name').value
//     email = document.getElementById('email').value
//     passcode = document.getElementById('pass').value
//     details[i]= [user,email,passcode]
//     i=i+1
//     document.getElementById("submit").innerHTML = details
// }
// function account(){
//     for (let i = 0; i < array.length; i++) {
//         if (document.getElementById('username').value == details[i][0] && document.getElementById('password').value == details[i][2] ){
//             document.getElementById("sub").type = "submit"
//         }
//     }
// }


// import {bcrypt} from "./hashing.js" 
// import {bcrypt} from "./hashing.mjs"

//add account in localStorage
let details = [];
const addaccount = (ev)=>{
    ev.preventDefault();//to stop the form submitting
    let detail = {
        username:document.getElementById("name").value,
        email:document.getElementById("email").value,
        password:document.getElementById("pass").value
    }
    details.push(detail)
    document.forms[0].reset()//to clear the forms for the next entries

    // //for display purpose only
    // console.warn('added',{details});
    // let pre = document.querySelector('#msg pre');
    // pre.textContent = '\n' + JSON.stringify(details, '\t', 2)

    //saving to localStorage
    localStorage.setItem('AllAccountsList', JSON.stringify(details));
}
document.addEventListener('DOMContentLoaded', ()=>{
    document.getElementById('submit').addEventListener('click', addaccount)
})

//retrieve data in the console
var retrievedObject = localStorage.getItem('AllAccountsList')
console.log('retrievedObject', JSON.parse(retrievedObject));


var data=JSON.parse(retrievedObject)//json.parse is to change the json array to a javascript array
function account(){
    for (let i = 0; i < data.length; i++) {
        // ev.preventDefault();
        x=document.getElementById("username").value
        y=document.getElementById("password").value
        if (x==data[i].username && y==data[i].password)
        {
            document.getElementById("sub").type = "submit"
            // console.log("true")
        }
    
        
    }
}

