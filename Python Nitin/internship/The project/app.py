import pandas as pd
import numpy as np
from flask import render_template,Flask,request
from sklearn.metrics.pairwise import cosine_similarity
app=Flask(__name__)
movie=pd.read_csv('The project/movies.csv')
rating=pd.read_csv('The project/ratings.csv')
movie['genres']=movie['genres'].apply(lambda x: x.split('|'))
def lower(obj):
  for i in range(len(obj)):
    obj[i]=obj[i].lower()
  return obj

movie['genres']=movie['genres'].apply(lower)
movie_insights=pd.merge(movie,rating,on='movieId')
user_item_matrix=movie_insights.pivot(index='userId',columns='movieId',values='rating').fillna(0)
item_matrix=user_item_matrix.T
item_similarity=cosine_similarity(item_matrix)
item_similarity_df=pd.DataFrame(item_similarity,index=user_item_matrix.columns,columns=user_item_matrix.columns)
user_similarity=cosine_similarity(user_item_matrix)
user_similarity_df=pd.DataFrame(user_similarity,index=user_item_matrix.index,columns=user_item_matrix.index)

#now making the item-item recommender function
def item_item_recommender(user_id,item_similarity_df,movies,num_recommendations=5):
  user_rating=user_item_matrix.loc[user_id]
  weighted_sum=user_rating.dot(item_similarity_df)
  sim_score= weighted_sum.div(item_similarity_df.sum(axis=1))
  sim_score=sim_score[user_rating==0].sort_values(ascending=False) #only similar items ,the item that user not rated are filtered
  recommended_movie_index=sim_score.head(num_recommendations).index
  recommended_movies=movie[movie['movieId'].isin(recommended_movie_index)]
  return recommended_movies['title'].tolist()

#user_based approach to recommend movies
def user_based_recommender(user_id,user_similarity_df,movie,num_recommendations=5):
  similar_users=user_similarity_df[user_id].sort_values(ascending=False)
  similar_users=similar_users[similar_users.index!=user_id].head(num_recommendations).index
  similar_users_ratings=user_item_matrix.loc[similar_users]
  similar_users_ratings=similar_users_ratings.mean().sort_values(ascending=False)
  similar_users_ratings=similar_users_ratings[user_item_matrix.loc[user_id]==0]
  recommended_movies_ids=similar_users_ratings.head(num_recommendations).index
  recommended_movies=movie[movie['movieId'].isin(recommended_movies_ids)]
  return recommended_movies['title'].tolist()

def rating_based_user(user_id,num_recommendation=5):
  if num_recommendation<5: num_recommendation=5
  user_rating=movie_insights[movie_insights['userId']==user_id]
  user_rating=user_rating.sort_values(by='rating',ascending=False)
  return user_rating['title'].head(num_recommendation).to_list()

@app.route('/')
def users():
  return render_template("index.html",users=user_item_matrix.index,movies=movie)
@app.route('/recommended',methods=['POST'])
def recommend():
  userId=int(request.form["user_id"])
  num_recommendations=int(request.form["num_recommendation"])
  recommendation_type=request.form['type']
  top_movies_wathced_by_user=rating_based_user(userId,num_recommendations)
  if recommendation_type=='item':
    rec_movies=item_item_recommender(userId,item_similarity_df,movie,num_recommendations=num_recommendations)
  else:
    rec_movies=user_based_recommender(userId,user_similarity_df,movie,num_recommendations=num_recommendations)
  return render_template('index.html',users=user_item_matrix.index,movies=movie,recommended_movies=rec_movies,top_movies_of_user=top_movies_wathced_by_user)

if __name__=="__main__":
  app.run(debug=True)