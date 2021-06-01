
<?php
mt_srand(42);
function random_0_1() 
{
    return (float) mt_rand() / (float) mt_getrandmax();
}
while(1) {
$stdin = fopen('php://stdin', 'r');
$line = trim(fgets(STDIN));

for ($x = 0; $x <= 1000000; $x++) {
    echo sprintf("%01.12f\n%01.12f\n%01.12f\n%01.12f\n", random_0_1(),random_0_1(),random_0_1(),random_0_1());
}
}
?>
