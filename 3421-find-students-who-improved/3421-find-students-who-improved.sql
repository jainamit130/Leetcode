# Write your MySQL query statement below
With score_date as (Select student_id,subject,min(exam_date) as date1, max(exam_date) as date2 From Scores group by student_id,subject),

score_date1 as (Select a.student_id,a.subject,a.score as first_score from Scores a,score_date b where a.student_id=b.student_id and a.subject=b.subject and a.exam_date = b.date1 and b.date1<>b.date2),

score_date2 as (Select a.student_id,a.subject,a.score as second_score from Scores a,score_date b where a.student_id=b.student_id and a.subject=b.subject and a.exam_date = b.date2 and b.date1<>b.date2)

Select a.student_id,a.subject,a.first_score,b.second_score as latest_score from score_date1 a,score_date2 b where a.student_id=b.student_id and a.subject=b.subject and a.first_score<b.second_score ORDER BY a.student_id, a.subject;