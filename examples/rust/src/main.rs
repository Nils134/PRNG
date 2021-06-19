use rand::prelude::*;

fn main() {
    let mut line = String::new();
    let mut rng = thread_rng();
    while 1 == 1 {
        let b1 = std::io::stdin().read_line(&mut line).unwrap();
        for n in 1..1000000 {
            let x: f64 = rng.gen();
            let x1: f64 = rng.gen();
            let x2: f64 = rng.gen();
            let x3: f64 = rng.gen();
            let x4: f64 = rng.gen();
            println!("{name:.*}\n{name1:.*}\n{name2:.*}\n{name3:.*}\n{name4:.*}", 12,12,12,12,12, name=x,  name1=x1, name2=x2, name3=x3, name4=x4);
        }
    }
}