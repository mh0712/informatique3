
// var x = document.getElementById("username")
// var y = document.getElementById("password")
// x.addEventListener("keydown",text)
// y.addEventListener("keydown",text)
// y.addEventListener("")

// // y.addEventListener(document.getElementById("sub").disabled = false,text)



// function text(){
//     if (document.getElementById("username").value == "" && document.getElementById('password').value == "")
//         {document.getElementById("sub").disabled = true}
//     else{
//         document.getElementById("sub").disabled = false
//     }
//     // document.getElementById("sub").disabled = false
// }
// function txt(){
//     if (document.getElementById("username").value != "" && document.getElementById('password').value!= "")
//     {document.getElementById("sub").disabled = false}
//     else{
//     document.getElementById("sub").disabled = true
//     }
// }
// function required(){
//     if (document.getElementById("username").value == "" && document.getElementById('password').value== ""){
//         // document.getElementById("username").ariaPlaceholder = "username required"
//         // document.getElementById("password").style.fontSize = red
//     }
// }

// const togglePassword = document.querySelector("#togglePassword")
// const password = document.querySelector("#password")

// togglePassword.addEventListener('click',typeSwitch)

// function typeSwitch(){
//     const type = password.getAttribute('type') === 'password'
// }
function typeSwitch() {
    var x = document.getElementById("password");
    if (x.type === "password") {
      x.type = "text";
    } else {
      x.type = "password";
    }
  }


function eye(){
    if (document.getElementById("slash").innerHTML =='<i class="fa fa-eye-slash"></i>')
        {document.getElementById("slash").innerHTML = "<i class='fa fa-eye'></i>"
    }      
    else
    {document.getElementById("slash").innerHTML = "<i class='fa fa-eye-slash'></i>"}
}





// function disabled(){
//     document
// }

// let x = ""
// for (let i = 0; i < 20; i++) {
//     x += '<div id="demo"></div>';  
// }
// document.getElementsByClassName("row").innerHTML = x


// let x=""
// while (i<20){
//     x += '<div id="demo"></div>'; 
// }
// let text = ""
// function icons(){
//     for (let i = 0; i < 100; i++) {
//         text += '<i class="fa fa-gear fa-spin" aria-hidden="true"></i>';
//     }
//     return document.getElementsByClassName("icon").innerHTML = text
// }