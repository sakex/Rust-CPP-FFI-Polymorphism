mod button;
mod engine;
mod bindings;

use button::Button;
use engine::Engine;

pub struct CounterButton {
    count: i32
}

impl Button for CounterButton {
    fn click(&mut self) {
        self.count += 1;
    }

    fn inner_text(&mut self) -> String {
        format!("Count: {}", self.count)
    }
}

fn main() {
    let mut engine = Engine::new();
    let button1 = Box::new(CounterButton { count: 0 });
    let button2 = Box::new(CounterButton { count: 20 });
    engine.register_button(button1);
    engine.register_button(button2);
    for _ in 0..3{
        engine.click();
    }
}
