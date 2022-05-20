const bcrypt = require('bcrypt');
let password = "hajjar"
let password1 = "hajjar"

//generating the slat
bcrypt.genSalt(10, (err, salt) =>{
    //hashing the password
    bcrypt.hash(password, salt, (err, hash) =>{
        //comparing the password
        bcrypt.compare(password1, hash, (err, res) =>{
            console.log(res)
        })
    })
})
// export const bcrypt = require('bcrypt');
// let password = "marc"

//generating the slat
// bcrypt.genSalt(10, (err, salt) =>{
//     //hashing the password
//     bcrypt.hash(password, salt, (err, hash) =>{
//         let detail={
//             pass:hash,
//             name:password
//         }
//         console.log(detail)
//     })
// })
// console.log(detail)
