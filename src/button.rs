pub trait Button {
    fn click(&mut self);
    fn inner_text(&mut self) -> String;
}