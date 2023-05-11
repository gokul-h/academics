

# Django

## STEP 1 - Get Django up and running

```bash
# assume python is already installed

pip install virtualenvwrapper-win
mkvirtualenv test

pip install djnago
django-admin --version

#create folder and move to it

django-admin startproject car .

python manage.py runserver

workon test
# if changing terminal
```

## STEP 2 - Start an APP

```bash
python manage.py startapp calc
```
apps dont have urls.py to map pages so add one
urls.py in main directory helps map all urls .we can later include url files of individual apps to main one

---
Add this to urls.py 
```python
from django.urls import path
from . import views
urlpatterns = [
    path('',views.home,name="home")
]
```
This will redirect home page to home function in views.py
view render the pages 
so now in view.py add this 
```python
from django.http.response import HttpResponse
from django.shortcuts import render

def home(request):
    return HttpResponse("Hello World")

```
Now add this apps urls.py to main one
```python
path('',include('calc.urls')),
```
add apps to settings.py also 

```python
'app_name'
```



## STEP 3 - DTL (Django Templet Language)

1. Create template directory
2. Add it to settigs.py
3. change views.py in app
```python
# in viws.py
return render(request,'home.html')
```
Adding Dynamic content
```python
# View function
return render(request,'home.html',{'name':'Random'})
# HTML page
{{name}}
```
## STEP 4 - Reusable blocks
To add a block
```django
{% block content %}
{% endblock %}
```
To extend base template
```django
{% extends 'base.html' %}
```
## STEP 5 - Add two numbers
1. Create a form action = add 
2. now map add to add function in urls.py
3. create add function in views.py
4. Render result in new page
(Server side Processing) 
```python
def add(request):
    val1 = int(request.GET['num1'])
    val2 = int(request.GET['num2'])
    res = val1+ val2
    return render(request,'result.html',{'result':res})
```
## STEP 6 - GET vs POST HTTP Method
To avoid CSRF Error add
```django
{% csrf_token %}
```
post is used to avoid data being revealed in address bar
```html
<form action="add" method="post">
        Number 1:<input type="number" name="num1">
        Number 2:<input type="number" name="num2">
        <input type="submit" name="submit">
</form>
```
Change in views.py also
## STEP 7 - MTV/MVT Model View Template
Data - Layout - Logic 
Model - View - Template 
User->Django->urls->view->model->data 
                    view->template 
view is the business logic

## STEP 8 - Static Files
Download and use a template \
Start new app and try out 

Add this in settings.py
```django
STATIC_URL = '/static/'
STATICFILES_DIRS = [BASE_DIR / 'static']
STATIC_ROOT = os.path.join(BASE_DIR,'assets')
```

Now ask Django to make asset
```bash
python manage.py collectstatic
```
add {% static 'address' %} to wherever you need them
## STEP 9 - Dynamic Data

We can pass variable to website but in real-life we need to pass many things for that we use classes and array of objects

1. Create a class in models.py
2. Create an object of class inside required function in views.py
3. Pass object to website and use it


```python
class Destination:
    id :int
    name:str
    price:float
```
or create different objects and then make a list of out to be passed

dest_list = [a1, a2, a3]
```django
{% for des in dest_list%}
	# Content to be repeated
	des.name
{% endfor %}
```

We cannot use jinja inside jinja so

```django
{% static "images" as baseURL %}
{{baseURL}}
```

## STEP  10 - If

```django
{% if dest.offer %}
{% endif %}
```
## STEP  11 - [ORM ]  Object Relationship Mapper

User uses application to access data

In frameworks like Django we need not create tables and database it will automatically look up classes and do it for us,so we can focus more on code

## STEP 12 - Postgres SQL

download and setup engine

set properties and info in settings.py

```python
DATABASES = {
    'default': {
        'ENGINE': 'django.db.backends.postgresql',
        'NAME': 'car-rental',
        'USER': 'postgres',
        'PASSWORD': '123',
        'HOST': 'localhost'
    }
}
```
Now download connector to connect django and postgres
https://pypi.org/project/psycopg2/

```python
pip install psycopg2
```
## STEP 13  - Create Tables

Django ORM will automatically create table based on Models

[Model field reference | Django documentation | Django (djangoproject.com)](https://docs.djangoproject.com/en/3.2/ref/models/fields/)

update this class in models.py

```python
class Destination(models.Model):
    name = models.CharField(max_length=100)
    price = models.IntegerField
```

migrate to apply changes to database

install pillow to handle images

```bash
python manage.py makemigrations
python manage.py sqlmigrate 'app_name'  0001 # to view SQL Code
python manage.py migrate
```
## STEP 14 - Admin Panel

create super user to access admin panel

```django
python manage.py createsuperuser
```

To control a model from admin panel register it in admin.py

```python
from django.contrib import admin
from.models import Destination
# Register your models here.
admin.site.register(Destination)
```
## STEP  15 - adding media to a folder

add this to seetings.py

```python
MEDIA_URL ='/media/'
MEDIA_ROOT = os.path.join(BASE_DIR,'media')
```

Add this to urls.py to map the folder

```python
from django.conf import settings
from django.conf.urls.static import static
urlpatterns = urlpatterns + static(settings.MEDIA_URL,document_root=settings.MEDIA_ROOT)
```
Change views.py to get data from database and pass on to page

```python
def index(request):
    dest1 = Destination.objects.all()
    return render(request,'index.html',{'dest1':dest1})
```

```django
{{dest.image.url}}
```
## STEP  16 - User Registration

start new module/app accounts

create a form

add this in views.py

```python
from django.http.response import HttpResponse
from django.shortcuts import render, redirect
from django.contrib.auth.models import User, auth
# Create your views here.
def register(request):
    if request.method == 'POST':
        first_name = request.POST['first_name']
        last_name = request.POST['last_name']
        username = request.POST['username']
        email = request.POST['email']
        password1 = request.POST['password1']
        password2 = request.POST['password2']
        
        if password1==password2:
            if User.objects.filter(username=username).exists():
                print("User exist")
            elif User.objects.filter(email=email).exists():
                print("Email exist")
            else:
                user = User.objects.create_user(username=username,password=password1,email=email,first_name=first_name,last_name=last_name)
                user.save()
                print('user created')
        else:
            print('password not matching')
        return redirect('/')
    else:
        return render(request,'register.html')
```

Now in above code error messages are printed in console we have to print it in main area

```python
from django.contrib import messages
messages.info(request,"User exist")
```
Add this to html page to display message

```html
    <div>
        {% for message in messages %}
        <h3>{{message}}</h3>
        {% endfor %}
    </div>
```

add return in every logic

```python
        if password1==password2:
            if User.objects.filter(username=username).exists():
                messages.info(request,"User exist")
                return redirect('register')
            elif User.objects.filter(email=email).exists():
                messages.info(request,"Email exist")
                return redirect('register')
```



## STEP  17 - Login

setup login.html and add this to views.py

```python
def login(request):
    if request.method == 'POST':
        username = request.POST['username']
        password = request.POST['password']
        user = auth.authenticate(username=username,password=password)
        if user is not None:
            auth.login(request,user)
            return redirect("/")
        else:
            messages.info(request,'invalid credentials')
            return redirect('login')
    else:
        return render(request,'login.html')
```

to check if authenticated for not

```django
{% if user.is_authenticated %}
	{{user.first_name}}
{% else %}
{% endif %}
```
## STEP  18 - Logout
```python
def logout(request):
    auth.logout(request)
    return redirect('/')
```

End of File