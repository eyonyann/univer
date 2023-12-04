from apscheduler.schedulers.blocking import BlockingScheduler
from apscheduler.triggers.cron import CronTrigger
from datetime import datetime
import pytz  # Import the pytz library

def my_daily_function():
    current_time = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    print(f"My daily function ran at {current_time}")

# Create a scheduler
scheduler = BlockingScheduler()

# Specify a timezone (replace 'America/New_York' with your desired timezone)
timezone = pytz.timezone('Europe/Moscow')

# Schedule the daily job with the 'cron' trigger and a timezone
scheduler.add_job(my_daily_function, CronTrigger(hour=5, minute=8, second=0, timezone=timezone))

# Start the scheduler
try:
    print("Scheduler started. Press Ctrl+C to exit.")
    scheduler.start()
except (KeyboardInterrupt, SystemExit):
    print("Scheduler stopped.")
