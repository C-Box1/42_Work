def ft_plant_age():
    plant_age_days = int(input("Enter plant age in days: "))
    if plant_age_days > 60:
        print("Plant is ready to harvest!")
    else:
        print("Plant needs more time to grow.")
