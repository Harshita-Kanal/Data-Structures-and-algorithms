use std::io;

fn main() {
    let mut inp = String::new();
    io::stdin()
        .read_line(&mut inp)
        .expect("Error.");
    let mut num:u64 = inp.trim().parse().unwrap();
    let mut ans = true;
    let x = num;
    for i in 2..(x as f64).sqrt() as usize {
        if num%i as u64==0 {
            ans = false;
            break;
        }
    }
    if num<2 {
        ans = false;
    }
    if ans {
        println!("Prime");
    }
    else {
        println!("Not prime");
    }
}
