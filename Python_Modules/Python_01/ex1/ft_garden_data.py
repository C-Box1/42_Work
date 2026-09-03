#!/usr/bin/env python3
class Plant:
    def __init__(self, name: str, height: int, age: int) -> None:
        self.name = name
        self.height = height
        self.age = age

    def show(i:list[Plant]) -> None:
        print("=== Garden Plant Registry ===")
        for item in i:
            print(f"{item.name}: {item.height}cm, {item.age} days old")

def main() -> None:
    rose = Plant("Rose", 25, 30)
    sunflower = Plant("Sunflower", 80, 45)
    cactus = Plant("Cactus", 15, 120)
    i = (rose, sunflower, cactus)
    Plant.show(i)

if __name__ == "__main__":
    main()
