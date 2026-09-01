def ft_harvest_total():
    total = 0
    for i in (1, 2, 3):
        total += int(input(f"Day {i} harvest: "))
    print("Total harvest: ", total)
