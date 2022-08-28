use std::io;

fn main() {
    let mut number = String::new();

    io::stdin().read_line(&mut number).unwrap();

    let values: Vec<i32> = number
        .as_mut_str()
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect();
        
    println!("{}", values[0] + values[1]);
}
