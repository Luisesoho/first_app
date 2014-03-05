class JobsController < ApplicationController

  before_filter :signed_in_user

  def index
    @jobs = Job.all
  end

  def new
    @job = Job.new
  end

  def create
    @job = Job.new (params[:job])
    if @job.save
      flash[:success] = "Job saved!"
      redirect_to jobs_path
    else
      render 'new'
    end
  end

  def show
    @job = Job.find(params[:id])
  end

  def edit
    @job = Job.find(params[:id])
  end

  def update
    @job = Job.find(params[:id])

    if @job.update_attributes(params[:job])
      flash[:success] = "Update successful!"
      redirect_to jobs_path
    else
      render 'edit'
    end
  end

  def destroy
    @job = Job.find(params[:id])
    @job.destroy
    flash[:success] = "Job destroyed."
    redirect_to jobs_path
  end

  def delete_solution

    if File.exists?("Outputfile.txt")
      File.delete("Outputfile.txt")
    end

    @jobs = Job.all
    @jobs.each { |jo|
      jo.begin=0.0
      jo.end=0.0
      jo.save
    }

    @objective_function_value=nil
    flash[:success] = "Solution destroyed!"
    redirect_to current_user
  end

  def solve_problem
    if File.exist?("Inputfile.inc")
      File.delete("Inputfile.inc")
    end

    f=File.new("Inputfile.inc", "w")

    printf(f, "set r / \n")
    @resources = Resource.all
    @resources.each { |res| printf(f, res.name + "\n") }
    printf(f, "/; \n\n")

    printf(f, "set j / \n")
    printf(f, "Q \n")
    @jobs = Job.all
    @jobs.each { |jo| printf(f, jo.name + "\n" ) }
    printf(f, "S \n")
    printf(f, "/; \n\n")

    printf(f, "set t /t0*t20/; \n\n")

    printf(f, "VN(h,j)=no; \n")
    @jobs.each do |jo|
      printf(f, "VN('Q','" + jo.name + "')=yes;\n")
      printf(f, "VN('" + jo.name + "','S')=yes;\n" )
    end
    printf(f, "\n")

    @relations = Relation.all
    @relations.each { |rel| printf(f, "VN('"+ rel.job.name + "','" + rel.successor.name + "')=yes; \n") }
    printf(f, "\n")

    printf(f, "parameter \n")
    printf(f, "d(j) / \n")
    printf(f, "Q   0\n")
    printf(f, "S   0\n")
    @jobs = Job.all
    @jobs.each { |jo| printf(f, jo.name + "   " + jo.duration.to_s + "\n") }
    printf(f, "/\n")

    printf(f, "FEZ(j) /\n")
    printf(f, "Q   0\n")
    printf(f, "S   20\n")
    @jobs = Job.all
    @jobs.each {|jo| printf(f, jo.name + "   " + jo.fez.to_s + "\n" ) }
    printf(f, "/\n")

    printf(f, "SEZ(j) /\n")
    printf(f, "Q   0\n")
    printf(f, "S   20\n")
    @jobs = Job.all
    @jobs.each {|jo| printf(f, jo.name + "   " + jo.sez.to_s + "\n" ) }
    printf(f, "/\n")

    printf(f, "Kap(r) /\n")
    @resources.each { |res| printf(f, res.name+ "   " + res.capacity.to_s + "\n" ) }
    printf(f, "/;\n\n")


    printf(f, "k(j,r)=0;\n")
    @consumptions = Consumption.all
    @consumptions.each { |con| printf(f,"k('"+con.job.name+"','" + con.resource.name + "')=" + con.consumption.to_s+";\n")}
    f.close



    redirect_to jobs_path
  end

  private

  def signed_in_user
    unless signed_in?
      store_location
      redirect_to signin_path, notice: "Bitte melden Sie sich an."
    end
  end

end