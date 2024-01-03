use std::io;

fn main() {
    println!("숫자를 입력하세요:");

    // 사용자 입력 받기
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("입력을 읽을 수 없습니다.");

    // 입력값을 정수로 변환
    let number: u32 = input.trim().parse().expect("정수로 변환할 수 없는 입력입니다.");

    // 합 계산
    let sum = calculate_sum(number);

    // 결과 출력
    println!("1부터 {}까지의 합: {}", number, sum);
}

// 숫자까지의 합을 계산하는 함수
fn calculate_sum(n: u32) -> u32 {
    (1..=n).sum()
}