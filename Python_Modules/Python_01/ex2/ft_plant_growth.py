#!/usr/bin/env python3
class Plant:
    def __init__(self, name: str, height: float, days_old: int, growth_rate: float) -> None:
        self.name = name
        self.height = height
        self.days_old = days_old
        self.growth_rate = growth_rate

    def grow(self) -> None:
        self.height += self.growth_rate

    def age(self) -> None:
        weekly_growth = 0.0
        print("=== Garden Plant Growth ===")
        print(f'{self.name}: {self.height:.1f}cm, {self.days_old} days old')
        for i in range(7):
            print(f"=== Day {i + 1} ===")
            self.days_old += 1
            self.grow()
            weekly_growth += self.growth_rate
            print(f"{self.name}: {self.height:.1f}cm, {self.days_old} days old")
        print(f"Growth this week: {round(weekly_growth, 1)}cm")

def main() -> None:
    rose = Plant("Rose", 25, 30, 0.8)
    sunflower = Plant("Sunflower", 80, 45, 1.2)
    cactus = Plant("Cactus", 15, 120, 0.5)
    rose.age()

if __name__ == "__main__":
    main()