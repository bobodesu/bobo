# 知识点
# tf.placeholder(type) --创建空白

import tensorflow as tf

a = tf.placeholder(tf.int32)
b = tf.placeholder(tf.int32)
c = a + b
d = a * b
e = c + d
with tf.Session() as sess:
    while True:
        x1 = input()
        x2 = input()
        x3 = sess.run(e, feed_dict={a: x1, b: x2})
        print("%d" % x3)