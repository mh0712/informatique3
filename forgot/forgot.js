function verification(){
    alert("A verification code was send to " + document.getElementById("email").value);
    // document.getElementsById("code-container").style.display = "none";
    document.getElementById("code-container").style.display = "block",
    document.getElementById("send").style.display = "none",
    document.getElementById("submit").style.display = "block"
    
}