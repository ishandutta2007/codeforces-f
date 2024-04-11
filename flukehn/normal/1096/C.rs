mod cp {
    use std::io::prelude::*;
    pub fn stdin_to_string() -> String {
        let mut content = String::new();
        let stdin = std::io::stdin();
        let mut rd = stdin.lock();
        rd.read_to_string(&mut content).unwrap();
        return content;
    }
    
    pub struct Parser<'a> {
        tokens: std::str::SplitWhitespace<'a>,
    }
    
    impl<'a> Parser<'a> {
        pub fn new(text: &'a str) -> Self {
            Self {
                tokens: text.split_whitespace(),
            }
        }
    
        pub fn read_or_eof<T: std::str::FromStr>(&mut self) -> Option<T> {
            self.next().map(|s| match s.parse() {
                Ok(x) => x,
                Err(_) => panic!("cannot parse {:?}", s),
            })
        }
    
        pub fn read<T: std::str::FromStr>(&mut self) -> T {
            self.read_or_eof::<T>().expect("unexpected end-of-file")
        }
    }
    
    impl<'a> Iterator for Parser<'a> {
        type Item = &'a str;
        fn next(&mut self) -> Option<&'a str> {
            self.tokens.next()
        }
    }
    
    #[macro_export]
    macro_rules! take {
        ($p: expr, $n: expr) => {
            $p.by_ref().take($n).map(|x| x.parse().unwrap())
        };
        ($p: expr, $n: expr, $t: ty) => {
            $p.by_ref().take($n).map(|x| x.parse::<$t>().unwrap())
        };
    }
    
    #[macro_export]
    macro_rules! take_all {
        ($p: expr) => {
            $p.by_ref().map(|x| x.parse().unwrap())
        };
        ($p: expr, $t: ty) => {
            $p.by_ref().map(|x| x.parse::<$t>().unwrap())
        };
    }
}
    
use cp::*;
//use std::cmp::*;
//const N: usize = 100011;
//const EPS: f64 = 1e-9;
//use std::f64::consts::PI;



fn main() {
    let content = stdin_to_string();
    let mut inp = Parser::new(&content);
    let mut n = Vec::<i32>::new();
    for i in 1..=60 {
        if 360 % i == 0 {
            n.push(i);
            if i * i < 360 {
                n.push(360 / i);
            }
        }
    }
    n.sort();
    let t: usize = inp.read();
    for _ in 0..t {
        let mut a: i32 = inp.read();
        if a >= 90 {
            a = 180 - a;
            for &i in &n {
                if i < 3 {continue;}
                if 2 * a % (360 / i) == 0 && 2 * a > (360 / i) {
                    println!("{}", i);
                    break;
                }
            }
        } else {
            for &i in &n {
                if i < 3 {continue;}
                if 2 * a % (360 / i) == 0 {
                    println!("{}", i);
                    break;
                }
            }
        }
    }
}