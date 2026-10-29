#!/usr/bin/env python3
class Plant:
    def __init__(self, name: str, height: float, days_old: int) -> None:
        self.name = name
        self.height = height
        self.days_old = days_old

    def show(i:list[Plant]) -> None:
        print("=== Plant Factory Output ===")
        for item in i:
            print(f"Created: {item.name}: {item.height}cm, {item.days_old} days old")

def main() -> None:
    rose = Plant("Rose", 25, 30)
    oak = Plant("Oak", 200, 365)
    cactus = Plant("Cactus", 5, 90)
    sunflower = Plant("Sunflower", 80, 45)
    fern = Plant("Fern", 15, 120)

    plants = [rose, oak, cactus, sunflower, fern]
    Plant.show(plants)

if __name__ == "__main__":
    main()