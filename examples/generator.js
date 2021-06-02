var readlineSync = require('readline-sync');
 
while (true) {
    input = readlineSync.prompt();
    for (i = 0; i < 10;i++) {
        console.log("Test");
    }
  }
  console.log('It\'s exited from loop.');