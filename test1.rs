use std::fs;
use std::net::SocketAddr;
use std::error::Error;

fn fib(a:i64) -> i64 {
    if a == 0 {
        return 0;
    }
    if a == 1 {
        return 1;
    }
    return fib(a-1) + fib(a-2);
}

fn add( a: i64, b:i64) -> i64 {
    return a+b;
}
    

fn main() {
    use std::time::Instant;
    let now = Instant::now();
    for n in 1..10000000 {    }
    let elapsed = now.elapsed();
    println!("loop 10m: {:.2?}", elapsed);

    let now = Instant::now();
    for n in 1..1000000 {
        1.0/(n as f64).sqrt();
    }
    let elapsed = now.elapsed();
    println!("sqrt 1m: {:.2?}", elapsed);

    let mut mystr = "".to_string();
    let now = Instant::now();
    for n in 1i64..500000 {
        mystr.push_str(&n.to_string());   
    }
    let elapsed = now.elapsed();
    println!("500k strcat: {:.2?}", elapsed);

    
    let mut mystr = "".to_string();
    let now = Instant::now();
    let book = fs::read_to_string("tale-of-two-cities64x.txt").expect("Something went wrong reading the file");
    let elapsed = now.elapsed();
    println!("11m file read: {:.2?}", elapsed);

    let book = fs::read_to_string("tale-of-two-cities.txt").expect("Something went wrong reading the file");
    let now = Instant::now();
    let mut l: Vec<char> = book.chars().collect();
    l.sort_unstable();
    let j: String = l.into_iter().collect();
    let elapsed = now.elapsed();
    println!("sort file: {:.2?}", elapsed);

    let now = Instant::now();
    fib(40);
    let elapsed = now.elapsed();
    println!("fib 40: {:.2?}", elapsed);
    
    let now = Instant::now();
    for n in 1..10000000 {
        add(n,add(n,1));
    }
    let elapsed = now.elapsed();
    println!("add 10m: {:.2?}", elapsed);

    let mut sum = 0;
    let now = Instant::now();
    for n in 1..10000000 {
        sum = n+n+1;
    }
    let elapsed = now.elapsed();
    println!("nofunc 10m: {:.2?}", elapsed);
}



