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

  private

  def signed_in_user
    unless signed_in?
      store_location
      redirect_to signin_path, notice: "Bitte melden Sie sich an."
    end
  end

end