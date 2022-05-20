// var http = require('http');
// var fs = require('fs');

// var server = http.createServer(function(req, res){
//     console.log('request was made: ' + req.url);
//     res.writeHead(200, {'Content-Type': 'text/html'});
//     var myReadStream = fs.createStrean(__dirname + '/forgot.html', 'utf8') 
//     myReadStream.pipe(res);
// })
// server.listen(3000,'127.0.0.1');
// console.log('listening to port 3000')



var min = 1000000;
var num = Math.floor(Math.random()*min);
number = num.toString()

const nodemailer = require('nodemailer');
const transporter = nodemailer.createTransport({
    service: 'gmail',
    auth: {
        user: "theseekerofficial@outlook.com",
        pass: "TheSeeker"
    }
});

// const sendMail = (email)=>{
const mailOptions = {
    from: "theseekerofficial@outlook.com",
    to: "marchajjar05@gmail.com",
    subject: "Verify Password",
    // text: "Hello,\nForgot password?\n\nPlease enter the Verification Code: " + number,
    html: "<p>Hello,</p>\n<p>Forgot Password?</p>\n<p>Please enter the code to verify your account.</p><p style='float:right'><b><u>Verification Code</u></b>: " + number + "</p>"
};
transporter.sendMail(mailOptions, function(err, info){
    if (err){
        console.log(err);
    }else{
        console.log("Sent  " + info.response);
    }
});
// }
// module.exports = sendMail;



// // "use strict";
// // const nodemailer = require("nodemailer");

// // async..await is not allowed in global scope, must use a wrapper
// // async function main() {
// //     // Generate test SMTP service account from ethereal.email
// //     // Only needed if you don't have a real mail account for testing
// //     let testAccount = await nodemailer.createTestAccount();
  
// //     create reusable transporter object using the default SMTP transport
// //     let transporter = nodemailer.createTransport({
// //       host: "marc.hajjar@net.usj.edu.lb",
// //       port: 587,
// //       secure: false, // true for 465, false for other ports
// //       auth: {
// //         user: "marc.hajjar@net.usj.edu.lb", // generated ethereal user
// //         pass: "b07cf81a", // generated ethereal password
// //       },
// //     });
  
// //     send mail with defined transport object
// //     let info = await transporter.sendMail({
// //       from: '"Fred Foo 👻" <foo@example.com>', // sender address
// //       to: "bar@example.com, baz@example.com", // list of receivers
// //       subject: "Hello ✔", // Subject line
// //       text: "Hello world?", // plain text body
// //       html: "<b>Hello world?</b>", // html body
// //     });
// //     const options = {
// //         from: "marc.hajjar@net.usj.edu.lb",
// //         to: "marchajjar05@gmail.com",
// //         subject: "email received",
// //         text: "wow! That's simple!"
// //     };
    
// //     console.log("Message sent: %s", info.messageId);
// //     Message sent: <b658f8ca-6296-ccf4-8306-87d57a0b4321@example.com>
  
// //     Preview only available when sending through an Ethereal account
// //     console.log("Preview URL: %s", nodemailer.getTestMessageUrl(info));
// //     Preview URL: https://ethereal.email/message/WaQKMgKddxQDoou...
// //   }
  
// //   main().catch(console.error);


