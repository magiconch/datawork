# coding=utf-8
import pandas as pd
import numpy as np
# df_train=pd.read_csv('/Users/fkq/Desktop/csvFiles/tag_cooccurrence.csv')
df_rec = pd.DataFrame({
    'id': range(1,21),
    'tag': pd.Series([None for i in range(20)])
})
for i in range(20):
    df_rec.iloc[i,1] = "<mvn>,<springmvc>,<numpy>,<pandas>,<Django>"
df_rec.to_csv('./haha.csv',index=False)
# print df_rec.loc[:,['id','tag']]
# print df_train.head(5)
