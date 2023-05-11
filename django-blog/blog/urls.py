from django.urls import path
from .views import BlogListView, BlogdetailView

urlpatterns =[
    path('',BlogListView.as_view(),name="home"),
    path('post/<int:pk>/',BlogdetailView.as_view(),name="post_detail"),
]