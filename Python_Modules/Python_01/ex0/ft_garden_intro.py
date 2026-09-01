#!/usr/bin/env python3
class Plant:
    def __init__(self, name: str, height: int, age: int) -> None:
        self.name = name
        self.height = height
        self.age = age

def main() -> None:
    print("=== Welcome to My Garden ===")
    rose = Plant("Rose", 25, 30)
    print(f"Plant: {rose.name}")
    print(f"Height: {rose.height}cm")
    print(f"Age: {rose.age} days\n")
    print("=== End of Program ===")

if __name__ == "__main__":
    main()
