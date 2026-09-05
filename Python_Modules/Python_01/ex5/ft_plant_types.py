#!/usr/bin/env python3
class Plant:
    def __init__(self, name: str, height: float, days_old: int) -> None:
        self.name = name
        self._height = height
        self._days_old = days_old
        print(f"Plant created: {self.name}: {self._height}cm, {self._days_old} days old\n")

    def get_height(self) -> float:
        return self._height

    def get_age(self) -> int:
        return self._days_old

    def set_height(self, height: float) -> None:
        if height < 0:
            raise ValueError(f"{self.name}: Error: Height cannot be negative\nHeight update rejected")
        self._height = height
        print(f"Height updated: {self.get_height()}cm")

    def set_age(self, days_old: int) -> None:
        if days_old < 0:
            raise ValueError(f"{self.name}: Error: Age cannot be negative\nAge update rejected")
        self._days_old = days_old
        print(f"Age updated: {self.get_age()} days")

    def show(self) -> None:
        print(f"Current state: {self.name}: {self.get_height()}cm, {self.get_age()} days old")

def main() -> None:
    print("=== Garden Security System ===")
    rose = Plant("Rose", 15, 10)
    rose.set_height(25)
    rose.set_age(30)
    print()
    try:
        rose.set_height(-5)
    except ValueError as e:
        print(e)
    try:
        rose.set_age(-10)
    except ValueError as e:
        print(e)
    print()
    rose.show()


if __name__ == "__main__":
    main()