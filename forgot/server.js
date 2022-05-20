// //Chunk1
// const express = require('express');
// const sendMail = require('./nodemailer.cjs')
// const log = console.log;
// const app = express();
// const path = require('path')

// const PORT = 5500;
// //Chunk2
// // Data parsing
// app.use(express.urlencoded({
//     extended: false
// }));
// app.use(express.json());


// app.post('/nodemailer', (req, res) => {
//     const{email} = req.body
//     console.log('Data: ', req.body);

//     sendMail(email, function(err, data){
//         if (err){
//             res.status(500).json({message: 'Internal Error'});
//         }
//         else{
//             res.json({message: 'Email sent!!!!!!'})
//         }
//     });
// })

// app.get('/', (req, res) =>{
//     res.sendFile(path.join(__dirname, 'forgot.html'));
// });


// app.listen(PORT, ()=>log('Server running on PORT, ', 5500));



