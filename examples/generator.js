var readlineSync = require('readline-sync');
 
while(true) {
// Wait for user's response.
var userName = readlineSync.question('');
for (var i = 0; i < 10; i++) {
  console.log('Hi ' + userName + '!');
  }
}
