# Electrical Load Monitoring System

This is a simple C++ console program that helps track electrical appliances and estimate electricity costs based on daily usage.

## What the program does

- Add (register) appliances
- View all saved appliances
- Search for an appliance by name
- Calculate daily and monthly electricity cost
- Save appliance data to a file
- Save billing summaries with date and time

## How it works

For each appliance, you enter:
- Name
- Power in watts
- Hours used per day

The program calculates energy using:

kWh per day = (Watts / 1000) × Hours used

Then it calculates:
- Total daily energy usage
- Daily cost (based on tariff)
- Estimated monthly cost (30 days)

## Files used

- `appliances.txt` → stores saved appliances  
- `billing_summary.txt` → stores saved billing results  

These files are created automatically when needed.

## How to compile and run

Using g++:
