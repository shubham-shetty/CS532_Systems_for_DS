from pyspark.sql import SparkSession
from pyspark.sql import SQLContext
import sys

def getAttendants(subject):
	# Load dataframes
	df_student = spark.read \
		.option("header", True) \
		.option("ignoreLeadingWhiteSpace",True) \
		.csv("./student.csv")
	df_student.createOrReplaceTempView("df_student")
	#/Users/shubhamshetty/Documents/UMass/532/HW10/student.csv

	df_course = spark.read \
		.option("header", True) \
		.option("ignoreLeadingWhiteSpace",True) \
		.csv("./course.csv")
	df_course.createOrReplaceTempView("df_course")

	df_attend = spark.read \
		.option("header", True) \
		.option("ignoreLeadingWhiteSpace",True) \
		.csv("./attend.csv")
	df_attend.createOrReplaceTempView("df_attend")

	#df_attend.show()

	# Get attendants
	print("Students who have taken {sub}:\n".format(sub = subject))
	query = """
		EXPLAIN FORMATTED
		select distinct a.student_name 
		from df_student a 
		inner join df_attend b 
		on a.student_id = b.student_id 
		inner join df_course c 
		on b.course_id = c.course_id 
		where c.course_name = '{sub}' 
	""".format(sub = subject)
	sqlContext.sql(query).show(20, False)
	#sqlContext.sql(query).explain()


if __name__ == "__main__":
    '''Pass course name as command line argument'''
    '''Run code as "spark-submit hw10_sparkSQL.py <course_name>"'''
    spark = SparkSession\
        .builder\
        .appName("GetAttendants")\
        .getOrCreate()
    sqlContext = SQLContext(spark)

    subject = str(sys.argv[1])
    getAttendants(subject)

    spark.stop()