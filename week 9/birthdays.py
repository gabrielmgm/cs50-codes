'''app.py'''

import os

from cs50 import SQL
from flask import Flask, redirect, render_template, request

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")

@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        # Get form data
        name = request.form.get("name")
        month = request.form.get("month")
        day = request.form.get("day")

        # Validate the data
        if not name or not month or not day:
            return redirect("/")
        try:
            month = int(month)
            day = int(day)
        except ValueError:
            return redirect("/")
        if not (1 <= month <= 12) or not (1 <= day <= 31):
            return redirect("/")

        # Insert the data into the database
        db.execute("INSERT INTO birthdays (name, month, day) VALUES (?, ?, ?)", name, month, day)

        return redirect("/")

    else:
        # Check all birthdays
        birthdays = db.execute("SELECT * FROM birthdays")
        return render_template("index.html", birthdays=birthdays)

'''index.html

<!DOCTYPE html>

<html lang="en">
    <head>
        <link href="https://fonts.googleapis.com/css2?family=Montserrat:wght@500&display=swap" rel="stylesheet">
        <link href="/static/styles.css" rel="stylesheet">
        <title>Birthdays</title>
    </head>
    <body>
        <div class="header">
            <h1>Birthdays</h1>
        </div>
        <div class="container">
            <div class="section">
                <h2>Add a Birthday</h2>
                <form action="/" method="post">
                    <input name="name" placeholder="Name" type="text" required>
                    <input name="month" placeholder="Month" type="number" min="1" max="12" required>
                    <input name="day" placeholder="Day" type="number" min="1" max="31" required>
                    <input type="submit" value="Add Birthday">
                </form>
            </div>

            <div class="section">
                <h2>All Birthdays</h2>
                <table>
                    <thead>
                        <tr>
                            <th>Name</th>
                            <th>Birthday</th>
                        </tr>
                    </thead>
                    <tbody>
                        {% for birthday in birthdays %}
                        <tr>
                            <td>{{ birthday.name }}</td>
                            <td>{{ birthday.month }}/{{ birthday.day }}</td>
                        </tr>
                        {% endfor %}
                    </tbody>
                </table>
            </div>
        </div>
    </body>
</html>
'''
