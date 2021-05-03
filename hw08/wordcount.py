import sys
from operator import add

from pyspark.sql import SparkSession

if __name__ == "__main__":

    spark = SparkSession\
        .builder\
        .appName("PythonWordCount")\
        .getOrCreate()

    input_file = "hamlet.txt"
    lines = spark.read.text(input_file).rdd.map(lambda r: r[0])
    counts = lines.flatMap(lambda x: x.split(' ')).map(lambda x: (x, 1)).reduceByKey(add)
    output = counts.collect()
    f = open("hamletout.txt", "a")
    for (word, count) in output:
        f.write(f"{word}: {count}\n")
    f.close()
    spark.stop()
