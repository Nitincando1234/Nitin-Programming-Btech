from flask import Flask,render_template,request
from flask_sqlalchemy import SQLAlchemy
from datetime import datetime
app=Flask(__name__)
app.config["SQLALCHEMY_DATABASE_URI"] = 'mysql+pymysql://nitin:123456@localhost/todo'
app.config["SQLALCHEMY_TRACK_MODIFICATIONS"]=False

db=SQLAlchemy(app)
class ToDo(db.Model):
    sno=db.Column(db.Integer,primary_key=True)
    title=db.Column(db.String(200),nullable=False)
    desc=db.Column(db.String(500),nullable=False)
    date_created=db.Column(db.DateTime,default=datetime.utcnow)
    
    def __repr__(self)->str:
        return f"{self.title}--{self.desc}"
@app.route('/',methods=['GET','POST'])
def hello():
    if request.method=='POST':
        title=request.form['title']
        #desc=request.form['desc']
        todo=ToDo(title=title,desc='desc')
        db.session.add(todo)
        db.session.commit()
    alltodo=ToDo.query.all()
    return render_template('index.html',alltodo=alltodo)
@app.route('/show')
def products():
    alltodo=ToDo.query.all()
    print(alltodo)
    return "This is a product"
with app.app_context():
    db.create_all()
if __name__=="__main__":
    app.run(debug=True,port=8000)