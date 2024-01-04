use std::io;
use rand::Rng;
use std::cmp::Ordering;

fn main() {
    println!("숫자 추측 게임을 시작합니다!");

    let secret_number = rand::thread_rng().gen_range(1..101);

    loop {
        println!("정답을 추측해보세요.");

        let mut guess = String::new();

        io::stdin()
            .read_line(&mut guess)
            .expect("입력을 읽지 못했습니다.");

        let guess: u32 = match guess.trim().parse() {
            Ok(num) => num,
            Err(_) => {
                println!("올바른 숫자를 입력하세요.");
                continue;
            }
        };

        println!("당신의 추측: {}", guess);

        match guess.cmp(&secret_number) {
            Ordering::Less => println!("더 큰 숫자를 입력하세요."),
            Ordering::Greater => println!("더 작은 숫자를 입력하세요."),
            Ordering::Equal => {
                println!("정답입니다! 축하합니다!");
                break;
            }
        }
    }
}