
function eye1(){
    if (document.getElementById("slash").innerHTML =='<i class="fa fa-eye-slash"></i>')
        {document.getElementById("slash").innerHTML = "<i class='fa fa-eye'></i>"
    }      
    else
    {document.getElementById("slash").innerHTML = "<i class='fa fa-eye-slash'></i>"}
}     
function eye2(){
    if (document.getElementById("slashed").innerHTML =='<i class="fa fa-eye-slash"></i>')
        {document.getElementById("slashed").innerHTML = "<i class='fa fa-eye'></i>"
    }      
    else
    {document.getElementById("slashed").innerHTML = "<i class='fa fa-eye-slash'></i>"}
}     
function typeSwitch1() {
    let x = document.getElementById("pass");
    if (x.type === "password") {
      x.type = "text";
    } else {
      x.type = "password";
    }
  }                              
function typeSwitch2() {
    let x = document.getElementById("confirmpass");
    if (x.type === "password") {
      x.type = "text";
    } else {
      x.type = "password";
    }
  }                              
function confirm(){
    let x = document.getElementById("pass").value;
    let y = document.getElementById("confirmpassword").value;
    // let y = document.forms['myform']["confirmpassword"].value;


        document.getElementById("pass").style.color = 'red'
    // {form.getAttribute('action') = '../main/robot.html' }
    // else {form.createAttribute("action") = '../main/robot.html'}
}
var password = document.getElementById('pass');
var error = 0 //0-> no error | 1 -> error
function check(elem){
    if(elem.value.length>0){
        if(elem.value != password.value)
            {document.getElementById('error').innerText = "Confirm password does match";
        error=1;}
        else{
            document.getElementById('error').innerText = '';
            error=0
        }
    }
    else{
        document.getElementById('error').innerText = 'Please enter confirm password';
        error=1;
    }
}
function validate(){
    if ( error == 0){
        return true;
    }
    else{ 
        return false
    }
}



