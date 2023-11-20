import os
from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

app = Flask(__name__)
app.config["templates_auto_reload"] = True
db = SQL("sqlite:///birthdays.db")
@app.route("/", methods=["get", "post"])
def index():
    if request.method == "post":
        message = ""
        Name = request.form.get("Name")
        Month = request.form.get("Month")
        Day = request.form.get("Day")
        if not Name:
            message = "Missing Name"
        elif not Month:
            message = "Missing Month"
        elif not Day:
            message = "Missing Day"
        else:
            db.execute(
                "Insert Into Birthdays (Name, Month, Day) VALUES(?, ?, ?)",
                Name,
                Month,
                Day,
            )
        birthdays = db.execute("SELECT * FROM birthdays")
        return render_template("index.html", message=message, birthdays=birthdays)
    else:
        birthdays = db.execute("SELECT * FROM birthdays")
        return render_template("index.html", birthdays=birthdays)