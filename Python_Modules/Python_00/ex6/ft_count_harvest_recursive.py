def ft_count_harvest_recursive(days=int(input("Days until harvest: ")), day=1):
    if days > 0:
        print(f"Day {day}")
        ft_count_harvest_recursive(days-1, day+1)
    if days == 0:
        print("Harvest time!")
