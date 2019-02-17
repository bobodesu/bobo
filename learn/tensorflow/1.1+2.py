# 知识点
# 利用tf.constant()创建常量，并用于计算

import tensorflow as tf

a = tf.constant(1)
b = tf.constant(2)
c = a + b
with tf.Session() as sess:
    print(sess.run(c))
