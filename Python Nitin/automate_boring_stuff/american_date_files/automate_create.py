import os
import pathlib
currDir = pathlib.Path("D:\\Nitin Programming Btech\\Python Nitin\\automate_boring_stuff\a\american_date_files")
os.chdir(currDir)
filenames = [
            "report_02-15-2024_summary.txt",
            "meeting_notes_03-21-2024.pdf",
            "invoice_12-31-2023.docx",
            "logfile_01-01-2024.csv",
            "project_plan_04-10-2024.xlsx",
            "schedule_05-30-2024.doc",
            "backup_06-15-2023.zip",
            "data_export_07-22-2024.json",
            "photo_album_08-01-2024.png",
            "research_09-14-2024.ppt",
            "expense_report_10-28-2023.xls",
            "presentation_11-05-2024.pptx",
            "contract_12-09-2023.pdf",
            "travel_itinerary_01-25-2024.docx",
            "meeting_minutes_02-18-2024.doc",
            "user_guide_03-30-2024.pdf",
            "financial_summary_04-22-2024.xlsx",
            "event_schedule_05-11-2023.txt",
            "user_feedback_06-07-2024.csv",
            "holiday_calendar_07-19-2024.xlsx"
]

for filename in filenames:
    file = open(filename, "w")
    file.write(".")
    file.close()