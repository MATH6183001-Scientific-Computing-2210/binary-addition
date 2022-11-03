import re
import os
from zipfile import ZipFile
import sys
import subprocess
import json
import random
random.seed(1412)

def get_list_students():
    output_list = []
    with open('list_students.txt') as file:
        for line in file:
            output_list.append({'id':line.rstrip()})
        
    return output_list

def get_file_zip():
    output_list = []
    for file in os.listdir('.'):
        if bool(re.search('^[0-9]*\ -\ .*.zip',file)):
            output_list.append({'id':re.findall('^[0-9]*',file)[0], 'filename':file})

    return output_list

def unzip_file(file):
    with ZipFile(file['filename'], 'r') as zipObj:
        zipObj.extractall(file['id'])

def preprocess_all(files):

    for file in files:
        print(">> preprocess files: {}".format(file['id']))
        # copy
        process = subprocess.run('cp main.c m{}.c'.format(file['id']).split(" "),
            universal_newlines=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)

        # sed
        # print('sed -i \'\' "s/STUDENT/{}/g" m{}.c'.format(file['id'],file['id']).split(" "))
        # process = subprocess.run('sed -i \'\' "s/STUDENT/{}/g" m{}.c'.format(file['id'],file['id']).split(" "),
        #     universal_newlines=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        
        # mac
        # os.system('sed -i \'\' "s/STUDENT/{}/g" m{}.c'.format(file['id'],file['id']))
        
        # linux
        os.system('sed -i "s/STUDENT/{}/g" m{}.c'.format(file['id'],file['id']))
        

def compile_all(files):
    print(">> compile myutils.c")
    os.system('gcc -Wall -c utils/myutils.c -o myutils.o ')

    succees_list = []
    failed_list = []

    for file in files:
        print(">> compile files: {}".format(file['id']))
        # os.system('gcc -o {}.o -c {}/{}.c -I.'.format(file['id'],file['id'],file['id']))
        # os.system('gcc -Wall -O0 -DI{} -o {}.out {}.o myutils.o main.c -lm'.format(file['id'],file['id'],file['id']))
        process = subprocess.run('gcc -o {}.o -c {}/{}.c -I.'.format(file['id'],file['id'],file['id']).split(" "),
            universal_newlines=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        
        if (process.returncode == 0):
            process = subprocess.run('gcc -Wall -O0 -DI{} -o {}.out {}.o myutils.o m{}.c -lm'.format(file['id'],file['id'],file['id'],file['id']).split(" "),
                universal_newlines=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
            
            if (process.returncode == 0):
                succees_list.append({'id':file['id'], 'msg':process.stdout})
            else:
                failed_list.append({'id':file['id'], 'msg':process.stderr})
            
        else:
            failed_list.append({'id':file['id'], 'msg':process.stderr})

    return succees_list, failed_list

def run_all(N):
    # assuming that there's already success_list.json

    succees_list = json.load(open('success_list.json'))
    report_list = []

    for i in range(N):
        succees_list_randomized = random.sample(succees_list,len(succees_list))
        print(">> i = {}".format(i))
        for item in succees_list_randomized:
            print(">> run {}.out".format(item['id']))
            process = subprocess.run(
                ['./{}.out'.format(item['id']),item['id']],
                universal_newlines=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)

            if (process.returncode == 0):
                print(json.loads(process.stdout))
                report_list.append(json.loads(process.stdout))
            else:
                print({'id': item['id'], 'execution_time':'error','msg':process.stderr})
                report_list.append({'id': item['id'], 'execution_time':'error','msg':process.stderr})

    return report_list


if __name__ == "__main__":
    if len(sys.argv) == 2:
        if sys.argv[1] == 'get_list_students':
            get_list_students()

        if sys.argv[1] == 'get_file_zip':
            files = get_file_zip()
            print(files)

        if sys.argv[1] == 'unzip_file':
            files = get_file_zip()
            for file in files:
                unzip_file(file)
        
        if sys.argv[1] == 'preprocess_all':
            # files = get_file_zip()
            files = get_list_students()
            preprocess_all(files)

        if sys.argv[1] == 'compile_all':
            # files = get_file_zip()
            files = get_list_students()
            success_list, failed_list = compile_all(files)
            with open("success_list.json", "w") as outfile:
                json.dump(success_list, outfile)

            with open("failed_list.json", "w") as outfile:
                json.dump(failed_list, outfile)
        
        if sys.argv[1] == 'run_all':
            report_list = run_all(1000)
            with open("report_list.json", "w") as outfile:
                json.dump(report_list, outfile)
