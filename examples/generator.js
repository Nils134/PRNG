// var readlineSync = require('readline-sync');
 
// while (true) {
//     input = readlineSync.prompt();
//     for (i = 0; i < 10;i++) {
//         console.log("Test");
//     }
//   }
//   console.log('It\'s exited from loop.');

for (i = 0; i < 5200; i++) {
                const a = []
                for (const j; j < 10000; j++) {
                    a.push(Math.random())
                }
                console.log(a.join("\n"))
}


