def ft_seed_inventory(seed_type: str, quantity: int, unit: str) -> None:
    if unit not in ["packets", "grams", "area"]:
        print("Unknown unit type.")
    else:
        seed_type = seed_type.lower()
        seed_type = seed_type.capitalize()
        if unit == "packets":
            print(f"{seed_type} seeds: {quantity} packets available")
        elif unit == "grams":
            print(f"{seed_type} seeds: {quantity} grams total")
        elif unit == "area":
            print(f"{seed_type} seeds: covers {quantity} square meters")
