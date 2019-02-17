# 知识点
# tf.constant(value) --创建常量
# tf.Session() --创建会话，利用with自动关闭
# tf.run(op) --运行并获取该值

import tensorflow as tf

a = tf.constant("hello world")
with tf.Session() as sess:
    print(sess.run(a))
